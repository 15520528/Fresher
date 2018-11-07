#!/bin/sh
ps aux|awk -v A="$1" '$11~A {print $2}'| xargs kill -9