#! /bin/bash

for F in ../../ressources/*; do
	echo $F;
	time (./hotrace < $F)>/dev/null;
done
