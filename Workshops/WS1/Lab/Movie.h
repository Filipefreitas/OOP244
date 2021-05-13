/*
Name: Filipe da Cunha de Freitas
Email: fda-cunha-de-freitas@myseneca.ca
ID: 155737190
Date: 2020-10-28
*/

#define _CRT_SECURE_NO_WARNINGS
#ifndef SDDS_MOVIE_H 
#define SDDS_MOVIE_H

namespace sdds {

    struct Movie {
        char m_title[128];
        int m_year;
        char m_rating[6];
        int m_duration;
        char m_genres[10][11];
        float m_consumerRating;
    };

	bool loadMovies();
	bool hasGenre(const Movie* mvp, const char genre[]);
	void displayMovie(const Movie* mvp);
	void displayMoviesWithGenre(const char genre[]);

};

#endif