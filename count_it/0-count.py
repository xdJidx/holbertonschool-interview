#!/usr/bin/python3
"""Count it!"""

import requests

def count_words(subreddit, word_list, after='', counts=None):
    """
    Recursively query the Reddit API, parse the titles of all hot articles,
    and print a sorted count of given keywords.
    """
    if counts is None:
        counts = {}

    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    params = {'limit': 100, 'after': after}

    response = requests.get(url, headers=headers, params=params)
    
    if response.status_code != 200:
        return

    data = response.json()
    articles = data.get('data', {}).get('children', [])

    if not articles:
        return

    for article in articles:
        title = article['data']['title'].lower().split()
        
        for word in word_list:
            word_lower = word.lower()
            word_count = title.count(word_lower)
            if word_lower in counts:
                counts[word_lower] += word_count
            else:
                counts[word_lower] = word_count

    after = data['data'].get('after')

    if after:
        count_words(subreddit, word_list, after, counts)
    else:
        # Sort and print the results
        sorted_counts = sorted(counts.items(), key=lambda x: (-x[1], x[0]))
        for word, count in sorted_counts:
            if count > 0:
                print(f"{word}: {count}")

# Exemple d'utilisation :
if __name__ == '__main__':
    count_words('programming', ['react', 'python', 'java', 'javascript', 'scala', 'no_results_for_this_one'])
