#!/bin/bash
# create hpp and cpp file for class

read -p "Enter class name : " NAME


#create needed files
_NAME_HPP="$NAME.hpp"
_NAME_CPP="$NAME.cpp"
_TMP="$NAME.tmp"

touch $_NAME_HPP
touch $_NAME_CPP
touch $_TMP

echo "You can type 'next' (or 'n') to ignore next questions "

echo "
#ifndef _"$NAME"_H__
# define _"$NAME"_H__" > $_NAME_HPP

echo "
#include \"$NAME_HPP\"

$NAME::$NAME(void) {};
~$NAME::$NAME(void) {};

" > $_NAME_CPP


#ask for include file
INCLUDE="start"

while read -p "Enter needed include  : " INCLUDE;
do

	if [[ ( $INCLUDE = "n" ) || ( $INCLUDE = "next" ) ]];
	then
		break
	fi
	echo "# include <$INCLUDE>" >> $_NAME_HPP
	echo "#include <$INCLUDE>" >> $_NAME_CPP

done

echo "
class $NAME {
	
	private	:" >> $_NAME_HPP
	

#ask for private variable
TYPE="start"

while read -p "Enter private variable (type) : " TYPE;
do

	if [[ ( $TYPE = "n" ) || ( $TYPE = "next" ) ]];
	then
		break
	fi
	read -p "Enter variable name : " VAR;
	echo "		$TYPE	_$VAR;" >> $_NAME_HPP
	CVAR=${VAR^}
	echo "		get"$CVAR"(void) const;" >> $_TMP
	echo "		set"$CVAR"($TYPE _$VAR);" >> $_TMP

done

echo "
	public	:
		$NAME(void);
		~$NAME(void);
" >> $_NAME_HPP

cat $_TMP >> $_NAME_HPP

echo "" >> $_NAME_HPP

#ask for public variable
TYPE="start"

while read -p "Enter public variable (type) : " TYPE;
do

	if [[ ( $TYPE = "n" ) || ( $TYPE = "next" ) ]];
	then
		break
	fi
	read -p "Enter variable name : " VAR;
	echo "		$TYPE	$VAR;" >> $_NAME_HPP

done

rm -f $_TMP

echo "};

#endif" >> $_NAME_HPP
