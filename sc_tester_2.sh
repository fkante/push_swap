#!/bin/bash

if [ -z "$1" ]; then
	inst_check_num='100'
else
	inst_check_num=$1
fi

if [ -z "$2" ]; then
	ok_check_num='100'
else
	ok_check_num=$2
fi


inst_check_5_arg ()
{
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | wc -l
}

ok_check_5_arg ()
{
	ARG=`ruby -e "puts (1..5).to_a.shuffle.join(' ')"`; ./push_swap $ARG | ./checker $ARG
	echo "$ARG" > logs_5
}

test_inst_5 ()
{
	count=0
	max=0
	min=0
	while [ $count -le $inst_check_num ]
	do
		ret=$( inst_check_5_arg )
		if [ $ret -le $min ] || [ $min -eq 0 ]; then
			min=$ret
		fi
		if [ $ret -ge $max ]; then
			max=$ret
		fi
		ave=$(($ave + $ret))
		((count++))
	done

	ave=$(($ave / count))
	echo FOR 5 VAR
	printf "Min ops =\t%d\nMax ops =\t%d\nAverage ops =\t%d\n" $min $max $ave
}

test_ok_5 ()
{
	echo 'checker 5:'
	count=0
	while [ $count -le $ok_check_num ];
	do
		if [ $( ok_check_5_arg )  != 'OK' ]; then
			echo False
			return 0
		fi
		((count++))
	done
	echo True
}

t2=$(test_inst_5 &)
wait

echo "$t2"
echo

test_ok_5
