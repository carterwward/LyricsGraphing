import requests
import re
import json
from pathlib import Path
import os
import sys
from spotify import get_spot_stats

artist = sys.argv[1]
album = sys.argv[2]
artist = artist[1:]
album_start_link = 'http://genius.com/albums/'
link = album_start_link + artist.replace(' ', '-').lower() + '/' + album.replace(' ', '-')
page = requests.get(album_start_link + artist.replace(' ', '-').lower() + '/' + album.replace(' ', '-').lower()).text.split('class')
album_song_list = []
lengths = []
for text in page:
    if '-lyrics' in text and 'a href' in text and 'chart_row-content' in text:
        try:
            album_song_list.append(re.findall('"([^"]*)"', text)[1])
        except:
            continue
lyrics = {}
for song in album_song_list:
    curr_song = song[20 + len(artist):-7]
    lyrics[curr_song] = []
    page = requests.get(song)
    page = page.text.split('\n')
    for chunk in page:
        try:
            if '<br>' in chunk or '</a></p>' in chunk:
                line = re.sub("([\(\[]).*?([\)\]])", "\g<1>\g<2>", chunk)
                if 'prevent-default' in line:
                    if '<i>' in line:
                        lyrics[curr_song].append(line[line.find('<i>') + 3:line.find('<br>')])
                    else:
                        if '</a>' in line:
                            lyrics[curr_song].append(line[line.find('1">') + 3:line.find('</a>')])
                        else:
                            lyrics[curr_song].append(line[line.find('0">') + 3:line.find('<br>')])
                else:
                    lyrics[curr_song].append(line[:line.find('<')])
        except:
            continue
    for lyric in range(len(lyrics[curr_song])):
        if 'prevent-default' in lyrics[curr_song][lyric]:
            new_lyric = lyrics[curr_song][lyric][lyrics[curr_song][lyric].find('\">') + 2:]
            lyrics[curr_song][lyric] = new_lyric
for song in lyrics:
    for phrase in lyrics[song]:
        if phrase == '[]':
            lyrics[song].remove('[]')
for song in lyrics:
    lyrics[song] = lyrics[song][2:]
path = Path(Path.cwd() / 'albums' / str(album.lower() + '_' + artist.lower()))
try:
    os.mkdir(path)
except:
    pass
for song in lyrics:
    with open(Path(path / str(song + '.txt')), 'w', encoding='utf-8') as outfile:
        for lyric in lyrics[song]:
            if lyric[-4:] == '</i>':
                lyric = lyric[:-4]
            if lyric[-8:] == '</i></a>':
                lyric = lyric[:-8]
            if '<' in lyric or '>' in lyric:
                lyric = re.sub("/<[^>]*>/g", "", lyric)
            if '</i><i>' in lyric:
                lyric = lyric[:lyric.find('</i><i>')] + lyric[lyric.find('</i><i>') + 7:]
            lyric = lyric.replace('()', '')
            if len(lyric) > 1:
                if lyric[-1] == ' ':
                    lyric = lyric[:-1]
            if '  ' in lyric or '[' in lyric or ']' in lyric or '-' == lyric or '"' == lyric or '“' == lyric:
                continue
            outfile.write(lyric + '\n')
# TODO if we dont get spot stats clear directory to flag they need to input a new album and artist
get_spot_stats(album, artist)