#!/usr/bin/node
//script that prints all characters of a Star Wars movie
const request = require('request');
const { argv } = require('process');

const url = `https://swapi-api.hbtn.io/api/films/${argv[2]}/`;

async function getNames(url) {
  return new Promise((resolve) => {
    request(url, (_err, _res, body) => {
      resolve(JSON.parse(body).name);
    });
  });
}

async function showNames(_err, _res, body) {
  for (const u of JSON.parse(body).characters) {
    console.log(await getNames(u));
  }
}

request(url, showNames);
