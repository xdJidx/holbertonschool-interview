#!/usr/bin/node

const request = require('request');

// Function to fetch characters of a specific movie from the Star Wars API
function fetchCharacters(movieId) {
	const url = `https://swapi.dev/api/films/${movieId}/`;

	request(url, (error, response, body) => {
		if (error) {
			console.error('Error:', error);
			return;
		}

		if (response.statusCode !== 200) {
			console.error('Failed to fetch data. Status Code:', response.statusCode);
			return;
		}

		const film = JSON.parse(body);
		console.log('Characters in', film.title + ':');
		film.characters.forEach((characterUrl) => {
			fetchCharacterName(characterUrl);
		});
	});
}

// Function to fetch and print character name
function fetchCharacterName(characterUrl) {
	request(characterUrl, (error, response, body) => {
		if (error) {
			console.error('Error:', error);
			return;
		}

		if (response.statusCode !== 200) {
			console.error('Failed to fetch character data. Status Code:', response.statusCode);
			return;
		}

		const character = JSON.parse(body);
		console.log(character.name);
	});
}

// Main function
function main() {
	const movieId = process.argv[2];
	if (!movieId) {
		console.error('Please provide a movie ID as the first argument.');
		return;
	}
	fetchCharacters(movieId);
}

main();
