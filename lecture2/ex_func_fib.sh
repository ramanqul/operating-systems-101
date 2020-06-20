#!/bin/bash

function fib {
	n=$1
	if (( n <= 1 ))
	then
		echo 1
	else
		echo $(( $( fib $((n-1)) ) + $( fib $((n-2)) ) ))
	fi
}

fib 10
