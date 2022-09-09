#!/usr/bin/python3
""" A recursive function that queries the Reddit API """
from collections import Counter, defaultdict
from requests import get



def count_words(subreddit, word_list, countWords=None, after=None):
    """ Results should be printed in descending order,
        by the count, and if the count is the same for
        separate keywords, they should then be sorted
        alphabetically (ascending, from A to Z).

        Words with no matches should be skipped and not printed.
        Words must be printed in lowercase. """
    params = {
        'limit': 100,
        'after': after
    }

    res = get(
        'https://www.reddit.com/r/{}/hot.json'.format(subreddit),
        headers = {'User-Agent': 'Mozilla/5.0'},
        params = params,
        allow_redirects=False
    )

    if res.status_code == 200:
        if countWords is None:
            countWords = defaultdict(int)

        data = res.json().get('data')
        page = Counter(
            word for article in data.get('children')
            for word in article.get('data').get('title').casefold().split()
        )
        for word in word_list:
            if word.casefold() in page:
                countWords[word.casefold()] += page.get(word.casefold())

        if data.get('after') is None:
            keyValue = sorted(countWords.items(), key=lambda x: x[0])
            for key, value in sorted(keyValue, key=lambda x: x[1], reverse=True):
                print('{}: {}'.format(key, value))
        else:
            count_words(subreddit, word_list, countWords, data.get('after'))
