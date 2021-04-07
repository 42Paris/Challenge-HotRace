#! /bin/bash

for F in ../../ressources/*; do
	echo $F;
	filea="$( basename $F )A";
	fileb="$( basename $F )B";
	time ( ( ./hotrace < $F ) > $filea);
	( python3 compare.py < $F ) > $fileb;
	diff $filea $fileb;
done

rm generated*