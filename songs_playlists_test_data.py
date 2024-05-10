import random
import string

def generate_songs(filename, num_songs):
    """Generate songs with an ID, title, and artist."""
    with open(filename, 'w') as f:
        for i in range(1, num_songs + 1):
            title = ''.join(random.choices(string.ascii_letters + string.digits, k=10))
            artist = ''.join(random.choices(string.ascii_letters + ' ', k=15))
            f.write(f"{i}, Song {title}, Artist {artist}\n")

def generate_playlists(filename, num_playlists, num_songs):
    """Generate playlists with an ID and a list of song IDs."""
    with open(filename, 'w') as f:
        for i in range(1, num_playlists + 1):
            songs_in_playlist = random.sample(range(1, num_songs + 1), k=random.randint(5, 20))
            songs_str = ', '.join(str(x) for x in songs_in_playlist)
            f.write(f"{i}, Playlist {i}, Contains songs: {songs_str}\n")

def main():
    num_songs = 1000  # Total number of songs to generate
    num_playlists = 100  # Total number of playlists to generate
    generate_songs('songs.txt', num_songs)
    generate_playlists('playlists.txt', num_playlists, num_songs)

if __name__ == '__main__':
    main()
