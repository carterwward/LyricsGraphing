import spotipy
from pathlib import Path
from spotipy.oauth2 import SpotifyClientCredentials
from spot_cred import SPOTIPY_CLIENT_ID, SPOTIPY_CLIENT_SECRET
sp = spotipy.Spotify(client_credentials_manager=SpotifyClientCredentials(SPOTIPY_CLIENT_ID, SPOTIPY_CLIENT_SECRET))
sp.trace = False

def clean_name(name):
    new_name = name.lower()
    if "/" in new_name:
        new_name = new_name.replace("/", "")
    if "?" in new_name:
        new_name = new_name.replace("?", "")
    if "!" in new_name:
        new_name = new_name.replace("!", "")
    if "." in new_name:
        new_name = new_name.replace(".", "")
    if "feat" in new_name:
        new_name = new_name[:new_name.find("feat") -1]
    if "  " in new_name:
        new_name = new_name.replace("  ", " ")
    return new_name

def get_spot_stats(album_name, artist_desired):
    album_name = album_name.replace('-', ' ')
    artist_desired = artist_desired.replace('-', ' ')
    results = sp.search(q = "album:" + album_name, type = "album")

    # get the right album
    for result in results["albums"]["items"]:
        for artist in result["artists"]:
            if artist_desired.lower() == artist["name"].lower():
                album_id = result["uri"]

    # get album tracks
    album = sp.album(album_id)
    tracks = album["tracks"]
    path = Path(Path.cwd() / 'albums' / str(album_name.lower().replace(' ', '-') + '_' + artist_desired.lower().replace(' ', '-')))
    # open(path / Path(str('spot_stats.txt')), 'w', encoding='utf-8')
    with open(Path(path / 'spot_stats.txt'), 'w', encoding='utf-8') as outfile:
        for track in tracks['items']:
            uri = track['uri']
            full_track = sp.track(uri)
            new_name = clean_name(full_track["name"])
            outfile.write(new_name + ", " + str(full_track["track_number"]) + ", " + str(full_track['duration_ms']/1000) + ", " + str(full_track["popularity"]) + '\n')
