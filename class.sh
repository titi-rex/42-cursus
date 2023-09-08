#!/bin/bash
# create hpp and cpp file for class

#intern function

#padding function
#add padding depending on longer variable type knew
padding () {
	PAD=""
	if [[ ${#arr[0]} -ge $SIZE  ]];
	then
		SIZE=$(( (${#arr[0]} / 4) * 4 + 4))
	fi
	if [[ ${#arr[0]} -lt $SIZE ]];
	then
		for (( i=${#arr[0]}; i < $SIZE; i+=4))
		do
			PAD="$PAD	"
		done
	fi
}

#padding function
get_function () {
	for (( i=1; i < ${#arr[@]}; ++i ))
	do
		FUNC="$FUNC${arr[$i]}"
		if [ $i -ne $(( ${#arr[@]} - 1 )) ];
		then
			FUNC="$FUNC "
		fi
	done
}


#start 
printf "\033[1;36mWelcome in class editor\033[0m\n"


#check if user already supply a classname, if not ask for it
if [[ -z $1 ]];
then

	read -p "Enter class name : " NAME
	if [[ ( $NAME = "" ) ]];
	then
		printf "\033[0;33mPlease insert a name next time...\033[0m\n"
		exit
	fi

else
	NAME=$1
fi


#hint and format
printf "Hint : \033[3mYou can press enter or write 'next' (or 'n') to ignore next questions\033[0m\n"
printf "\033[4mExpected format :\033[0m\n"
printf "Include : \033[3minclude\033[0m or \033[3m\"include\"\033[0m for local file\n"
printf "Variable :\033[3m type name \033[0m (example : int number)\n"
printf "Function :\033[3m type name(type1 var1, ..., typen varn) \033[0m (example : void hello(void) const)\n"


#initialize name variable
_NAME_HPP="$NAME.hpp"
_NAME_CPP="$NAME.cpp"
_TMP="$NAME.tmp"


#create include guard
INCLUDE_GUARD="_"
for (( i=0; i<${#NAME}; ++i))
do

	if [[ "${NAME:$i:1}" =~ [[:upper:]] ]];
	then
		INCLUDE_GUARD="$INCLUDE_GUARD""_"
	fi
	INCLUDE_GUARD="$INCLUDE_GUARD${NAME:$i:1}"

done
INCLUDE_GUARD="${INCLUDE_GUARD^^}_H__"


#write start of files
echo "
#ifndef $INCLUDE_GUARD
# define $INCLUDE_GUARD" > $_NAME_HPP

echo "
#include \""$_NAME_HPP"\"" > $_NAME_CPP


#ask for include file
read -a arr -p "Enter all needed includes  : ";
for INCLUDE in "${arr[@]}";
do

	if [[ ( $INCLUDE = "" ) || ( $INCLUDE = "n" ) || ( $INCLUDE = "next" ) ]];
	then
		break
	fi

	if [ ${INCLUDE:0:1} == "\"" ]
	then
		echo "# include $INCLUDE" >> $_NAME_HPP
		echo "#include $INCLUDE" >> $_NAME_CPP
	else
		echo "# include <$INCLUDE>" >> $_NAME_HPP
		echo "#include <$INCLUDE>" >> $_NAME_CPP
	fi

done


#add default constructor and destructor in cpp file
echo "
$NAME::$NAME(void) {};

$NAME::~$NAME(void) {};

" >> $_NAME_CPP


#write private section
printf "\033[0;31m!---PRIVATE SECTION---!\033[0m\n"
printf "\033[3mAutomatic '_' prefix\033[0m\n"

echo "
class $NAME {
	
	private	:" >> $_NAME_HPP
	

#ask for private variable
SIZE=4
while read -a arr -p "Enter variable : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	padding

	#uppercase first letter to match camelCase
	CVAR=${arr[1]}
	CVAR=${CVAR^}

	GET="get"$CVAR"(void) const"
	SET="set"$CVAR"(${arr[0]} ${arr[1]})"

	#write private variable with padding and '-' prefix
	echo "		${arr[0]}""$PAD""_${arr[1]};" >> $_NAME_HPP

	#store get and set function int mp file int order to write it latter in public section
	echo "		${arr[0]}	$GET;" >> $_TMP
	echo "		void	$SET;" >> $_TMP

	#write get and set in cpp file
	echo "${arr[0]}	$NAME::$GET { return (this->_${arr[1]}); };
	" >> $_NAME_CPP
	echo "void	$NAME::$SET { this->_${arr[1]} = ${arr[1]}; };
	" >> $_NAME_CPP

done

#ask for private function
SIZE=4
while read -a arr -p "Enter private function : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	padding
	get_function

	#write function protoype in hpp and cpp files
	echo "		${arr[0]}""$PAD""_$FUNC;" >> $_NAME_HPP
	echo "${arr[0]}	$NAME::_$FUNC {};
	" >> $_NAME_CPP
	FUNC=""

done


#write public section
printf "\033[1;32m!---PUBLIC SECTION---!\033[0m\n"

echo "
	public	:" >> $_NAME_HPP


#ask for public  variable
SIZE=4
while read -a arr -p "Enter public  variable : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	padding

	#write variable in hpp file
	echo "		${arr[0]}""$PAD""${arr[1]};" >> $_NAME_HPP

done


#add default constructor and destructor in hpp file
echo "
		$NAME(void);
		~$NAME(void);
" >> $_NAME_HPP


#copy get and set function prototype in hpp file and add newline
cat $_TMP >> $_NAME_HPP
echo "" >> $_NAME_HPP


#aask for public functions
SIZE=4
while read -a arr -p "Enter public function : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	padding
	get_function

	#write function in hpp and cpp files
	echo "		${arr[0]}""$PAD""$FUNC;" >> $_NAME_HPP
	echo "${arr[0]}	$NAME::$FUNC {};
	" >> $_NAME_CPP
	FUNC=""

done

#write end of hpp file
echo "};

#endif" >> $_NAME_HPP


#delete temp file
rm -f $_TMP


