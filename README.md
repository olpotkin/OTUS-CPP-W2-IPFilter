# OTUS-CPP-W2: ip_filter

[![Build Status](https://travis-ci.org/olpotkin/OTUS-CPP-W2-IPFilter.svg?branch=master)](https://travis-ci.org/olpotkin/OTUS-CPP-W2-IPFilter)

## Environment
- `docker pull ubuntu:trusty`

## Setup instructions
- `echo "deb https://dl.bintray.com/olpotkin/OTUS-CPP-COURSE trusty main" | sudo tee -a /etc/apt/sources.list`
- `apt update && apt install -y helloworld`

In case of the error "<i>The method driver /usr/lib/apt/methods/https could not be found.</i>":
- `cd /usr/lib/apt/methods`
- `ln -s http https`

## Copy data from host to container:
- From host to container: `docker cp src/file.txt mycontainer:/target`
- From container to host: `docker cp mycontainer:/src/file.txt target`
- For this project: `docker cp /OTUS-CPP-W2-IPFilter/ip_filter.tsv elastic_perlman:/`
