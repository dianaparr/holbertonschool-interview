# 0x17. Find the Loop

## Tasks

**0. Find the loop:**

Write a function that finds the loop in a linked list.

- Prototype: `listint_t *find_listint_loop(listint_t *head);`
- Returns: The address of the node where the loop starts, or `NULL` if there is no loop
- You are not allowed to use `malloc`, `free` or arrays
- You can only declare a maximum of two variables in your function

Note: In order to compile the main file, you are provided with [this static library](https://s3.amazonaws.com/intranet-projects-files/interviews/472/libloop.a). This library won’t be used during the correction; Its only purpose is for testing.

If you want to use source file instead of the `libloop.a` library, please use this file [lib.c](https://holbertonintranet.s3.amazonaws.com/uploads/text/2021/1/79eebf4f9215073644b8cd766a88c8a3f3a0fd88.c?X-Amz-Algorithm=AWS4-HMAC-SHA256&X-Amz-Credential=AKIARDDGGGOU5BHMTQX4%2F20221007%2Fus-east-1%2Fs3%2Faws4_request&X-Amz-Date=20221007T022226Z&X-Amz-Expires=345600&X-Amz-SignedHeaders=host&X-Amz-Signature=477e2ec6feb6d34f7b0996ed392236938f29e27c85667ea6eba7e4e876042c08).

And compile it with this command: `$ gcc -Wall -pedantic -Werror -Wextra 0-main.c 0-find_loop.c lib.c -o main`
