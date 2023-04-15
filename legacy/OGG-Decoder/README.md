# Ogg decoder

## About
Very simple bare bones ogg file decoder

I am aware of different libraries that do the work of decoding files like [ffmpeg](http://ffmpeg.org/), [libvorbis](http://vorbis.com/) and [Tremor](https://wiki.xiph.org/Tremor) to name a few, I just wanted to see how decoding these files worked and if I was able to implemet a decoder for a few of them

`TL;DR`

I was bored so I reinvented the wheel

## Build

### Dependicies
`g++`

`make`

### Run the program 

```bash
./bin/ogg_decode <filepath>
```

(If you are expecting to see output information about the decode process, most of the information will be dumped into a log file located in `logs/info_log.txt`)

## TODO

- File Mappings
(for the record I did not look into all of these
extensively so I don't know if each one is possible
implement from an open source standpoint)
  - [ ] CMML
  - [ ] FLAC
  - [ ] Kate
  - [ ] Opus
  - [ ] PCM
  - [ ] Skeleton
  - [ ] Speex
  - [ ] Theora
  - [ ] Vorbis (currently being worked on)
  - [ ] Writ
