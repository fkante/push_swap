#!/bin/bash
make
echo "\e[36m";
echo "\n--- [ ANALYSING PUSH_SWAP] ---";
echo "\e[0m";

read -p "How many range of number [from ... to] (2 number needed) : " NBRBOT NBRTOP
read -p "How many loop : " TRY
read -p "Limit for test : " LIM
NBR=$(($NBRTOP - $NBRBOT))
((NBR++))
MOY=0;
MAX=-1;
MIN=-1;
ACTMAX="";
ACTMIN="";
MORE=0;
LESS=0;
IND=$TRY;
WELL=0;
TEST="";

printf "[ NBR == $NBR && TRY == $TRY && LIM == $LIM ]\n"

echo "Analyse in progress ...\n\n";
while [ $IND -gt 0 ];
do
	ARG=`ruby -e "puts ($NBRBOT..$NBRTOP).to_a.shuffle.join(' ')"`
	NBSTEP=$(./push_swap $ARG | wc -l);
	TEST=$(./push_swap $ARG | ./checker $ARG);
	if [ $TEST = "OK" ]
	then
		printf "\033[0;32m▓\033[0;0m"
		WELL=$(( $WELL + 1 ));
	else
		printf "\033[0;31m▓\033[0;0m"
	fi;

	if [ $MAX -lt $NBSTEP ]
	then 
		MAX=$NBSTEP; 
		ACTMAX=$ARG; 
	fi;
	if [ $MIN -eq "-1" ];
	then 
		MIN=$NBSTEP; 
		ACTMIN=$ARG; 
	fi;
	if [ $NBSTEP -lt $MIN ]
	then MIN=$NBSTEP; 
		ACTMIN=$ARG; 
	fi;
	MOY=$(( $MOY + $NBSTEP ));
	IND=$(( $IND - 1 ));
	if [ $NBSTEP -gt $LIM ]
	then 
		((MORE=MORE+1))
	else
		((LESS=LESS+1))
	fi;
done;
MOY=$(( $MOY / $TRY ));
echo "\nThere is \e[33m$WELL/$TRY\e[0m correct answer"
echo "There is \e[31m$MORE\e[0m more than $LIM"
echo "There is \e[32m$LESS\e[0m less than $LIM"
echo "The biggest  is :\eb[31m$MAX\e[0m"
echo "The average is :\t\e[33m$MOY\e[0m"
echo "The smallest is :\e[32m$MIN\e[0m"
echo "The worst list :\t$ACTMAX"
echo "The best list :\t\t$ACTMIN"
