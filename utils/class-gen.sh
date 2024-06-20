#!/bin/bash
# create hpp and cpp file for class

VERSION="V3.2"

#intern function

#padding function
#add padding depending on longer variable type knew
padding () {
	PAD=""
	if [[ ${#TYPE} -ge $SIZE  ]];
	then
		SIZE=$(( (${#TYPE} / 4) * 4 + 4))
	fi
	if [[ ${#TYPE} -lt $SIZE ]];
	then
		for (( i=${#TYPE}; i < $SIZE; i+=4))
		do
			PAD="$PAD	"
		done
	fi
}

#get type of variable
get_type_var () {
	TYPE="${arr[0]}"
	for ((i=1; i<${#arr[@]} - 1; ++i))
	do
		TYPE="$TYPE ${arr[i]}"
	done
}

#adapt TYPE and STATIC dpending on static var presence
adapt_static () {
	if [[ ${arr[0]} == "static" ]];
	then
		STATIC="static "
		TYPE="${arr[1]}"
		for ((i=2; i<${#arr[@]} - 1; ++i))
		do
			TYPE="$TYPE ${arr[i]}"
		done
	else
		STATIC=""
	fi
}

#get start of function
get_start_func () {
	START=""
	for (( i=0; i < ${#arr[@]}; ++i ))
	do
		if [[ ${arr[$i]} =~ [()] ]];
		then
			START=$i
			break ;
		fi
	done
}

#get return type of function
get_type_func () {
	TYPE="${arr[0]}"
	for (( i=1; i < $START; ++i ))
	do
		TYPE="$TYPE ${arr[$i]}"
	done
}

#get function
get_function () {
	FUNC=""
	for (( i=$START; i < ${#arr[@]}; ++i ))
	do
		FUNC="$FUNC${arr[$i]}"
		if [ $i -ne $(( ${#arr[@]} - 1 )) ];
		then
			FUNC="$FUNC "
		fi
	done
}


#start 
printf "\033[1;36mWelcome in class editor $VERSION\033[0m\n"


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
printf "Inheritance : \033[3macces-specifier name\033[0m each class and his specifier must me separated by blank\n"
printf "Variable :\033[3m type name \033[0m (example : int* number) \033[0;31m(please do not stick * or & to name)\033[0m\n"
printf "Function :\033[3m type name(type1 var1, ..., typen varn) \033[0m (example : void hello(void) const)\n"


#initialize name variable
_NAME_HPP="$NAME.hpp"
_NAME_CPP="$NAME.cpp"


#create include guard
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
echo "#ifndef $INCLUDE_GUARD
# define $INCLUDE_GUARD" > $_NAME_HPP

echo "#include \""$_NAME_HPP"\"" > $_NAME_CPP


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
	else
		echo "# include <$INCLUDE>" >> $_NAME_HPP
	fi
done


#ask heritage
read -a arr -p "Enter all parents class : ";
if [[ -n ${arr[0]} ]];
then
	INHERITANCE=":"
	H_CPYC=":"
	H_DEFC=":"
	for (( i=0; i<${#arr[@]}; ++i ))
	do
		if [[ ($i == $(( ${#arr[@]} - 1 )) ) || (${arr[$i]} == "private") || (${arr[$i]} == "protected") || (${arr[$i]} == "public") || (${arr[$i]} == "virtual") ]];
		then
			INHERITANCE="${INHERITANCE} ${arr[$i]}"
		else
			INHERITANCE="${INHERITANCE} ${arr[$i]},"
			H_CPYC="${H_CPYC} ${arr[$i]}(src),"
			H_DEFC="${H_DEFC}${arr[$i]}(),"
		fi
	done
	H_CPYC="${H_CPYC} ${arr[-1]}(src)"
	H_DEFC="${H_DEFC}${arr[-1]}()"
fi

#write private section
printf "\033[1;31m!---PRIVATE SECTION---!\033[0m\n"
printf "\033[3mAutomatic '_' prefix\033[0m\n"

echo "
class $NAME $INHERITANCE
{
	
	private	:" >> $_NAME_HPP
	

#ask for private variable
SIZE=4
while read -a arr -p "Enter variable : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	get_type_var
	padding
	adapt_static

	#uppercase first letter to match camelCase
	NVAR=${arr[${#arr[@]} - 1]}
	CVAR=$NVAR
	CVAR=${CVAR^}

	GET="get"$CVAR"(void) const"
	SET="set"$CVAR"($TYPE $NVAR)"

	#write private variable with padding and '-' prefix
	echo "		$STATIC$TYPE""$PAD""_$NVAR;" >> $_NAME_HPP

	#store get and set function int mp file int order to write it latter in public section
	TMP_HPP="${TMP_HPP}		$TYPE	$GET;\n"
	TMP_HPP="${TMP_HPP}		void	$SET;\n"

	#store get and set funciton 
	FUNC_PROTO="${FUNC_PROTO}$TYPE	$NAME::$GET { return (this->_$NVAR); };\n"
	FUNC_PROTO="${FUNC_PROTO}void	$NAME::$SET { this->_$NVAR = $NVAR; };\n\n"
	#store for constructor and operator=
	CONS="${CONS}_$NVAR(0), "
	OPEG="${OPEG}this->set${CVAR}(src.get${CVAR}());
	"

done


#ask for private function
SIZE=4
while read -a arr -p "Enter private function : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	get_start_func

	if [[ $START == "" ]];
	then
		printf "Wrong function format \n"
		continue ;
	fi

	get_type_func
	padding
	get_function

	#write function protoype in hpp and cpp files
	echo "		$TYPE""$PAD""_$FUNC;" >> $_NAME_HPP
	#store function protoype
	FUNC_PROTO="${FUNC_PROTO}$TYPE	$NAME::_$FUNC {};\n\n"

done


#write public section
printf "\033[1;32m!---PUBLIC SECTION---!\033[0m\n"

echo "
	public	:" >> $_NAME_HPP


#ask for public variable
SIZE=4
while read -a arr -p "Enter variable : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	get_type_var
	padding
	adapt_static

	NVAR=${arr[${#arr[@]} - 1]}
	#write variable in hpp file
	echo "		$TYPE""$PAD""$NVAR;" >> $_NAME_HPP
	#store for constructor and operator=
	CONS="${CONS}$NVAR(0), "
	OPEG="${OPEG}this->$NVAR = src.$NVAR;
	"

done


#add default constructor and destructor in hpp file
echo -e "
		$NAME(void);
		$NAME(const $NAME& src);
		$NAME&	operator=(const $NAME& src);
		~$NAME(void);

$TMP_HPP" >> $_NAME_HPP


#add default constructor and destructor in cpp file
if [[ -n $CONS ]];
then
	CONS=" : ${CONS:0:${#CONS[@]} - 3}"
fi
echo -e "
$NAME::$NAME(void)$CONS {};

$NAME::$NAME(const $NAME& src) $H_CPYC
{
	${OPEG}
};

$NAME&	$NAME::operator=(const $NAME& src) 
{
	if (this == &src)
		return (*this);
	${OPEG}return (*this);
};

$NAME::~$NAME(void) {};

$FUNC_PROTO" >> $_NAME_CPP


#ask for public functions
SIZE=4
while read -a arr -p "Enter public function : ";
do

	if [[ ( ${arr[0]} = "" ) || ( ${arr[0]} = "n" ) || ( ${arr[0]} = "next" ) ]];
	then
		break
	fi

	get_start_func

	if [[ $START == "" ]];
	then
		printf "Wrong function format \n"
		continue ;
	fi

	get_type_func
	padding
	get_function

	#write function in hpp and cpp files
	if [[ ${arr[0]:0:${#NAME}} == $NAME ]];
	then
		echo "		$FUNC;" >> $_NAME_HPP
		echo "$NAME::$FUNC $H_DEFC{};
	" >> $_NAME_CPP
	else
		echo "		${arr[0]}""$PAD""$FUNC;" >> $_NAME_HPP
		echo "${arr[0]}	$NAME::$FUNC {};
	" >> $_NAME_CPP
	fi
done


#write end of hpp file
echo "};

#endif" >> $_NAME_HPP

