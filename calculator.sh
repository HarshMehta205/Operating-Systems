#To write a shell scripting to implement addition, subraction ,division and multiplication using control structures




#!/bin/bash
#usuage:bash cal.sh

function add()						#function for addition
{
        m=$1						#positional parameter
        n=$2
        result=`expr $m + $n`				#performing addition expression
        return $result
}

function sub()						#function for subraction
{
        m=$1
        n=$2
        result=`expr $m - $n`				#performing subraction expression
        return $result
}


function mul()						#function for multiplication
{
        m=$1
        n=$2
 	result=`expr $num1 \*  $num2`	     #performing multiplication expression using \*
        return $result
}

function div()						#function for division
        m=$1
        n=$2
        result=`echo "scale=2;$num1 / $num2" |  bc`	#performing division expression 
        				#we use scale=2 so that we can display upto 2 decimal numbers
        echo "divide is : $result"
}

							#start of main function
echo "enter two numbers "
echo "first number :"
read num1
echo $num1
echo "second number :"
read num2
echo $num2


while :								#using while loop
do

	
        echo -e "\n enter your choice"
        echo -e "1.addition \n2.subraction \n3.multiply \n4.divide \n5.exit"
        echo "enter choice"
        read choice
        case $choice in						#switch case
        
        	1)      add $num1 $num2				#calling of function 
        		result=$?		 #using $? variable to know the exit status of pervious command
			echo "addition is : $result"		#displaying result
                        ;;

                2)      sub $num1 $num2
                	result=$?
			echo "subtraction is : $result"
                        ;;

                3)      mul $num1 $num2
                	result=$?
			echo "multiply is : $result"
                        ;;

                4)      div $num1 $num2				#we dont use $? command ads there is in-built fault with it
                        ;;


                5)     exit					#exit case
                        ;;

                *)      echo "no valid choice "			#default case
                        ;;

        esac
done



#-------------------------------------------------------------------------------------------------
output -
ibm@IBM:~/mehta$ nano cal.sh
ibm@IBM:~/mehta$ bash cal.sh
enter two numbers 
first number :
5
5
second number :
2
2

 enter your choice
1.addition 
2.subraction 
3.multiply 
4.divide 
5.exit
enter choice
1
addition is : 7

 enter your choice
1.addition 
2.subraction 
3.multiply 
4.divide 
5.exit
enter choice
2
subtraction is : 3

 enter your choice
1.addition 
2.subraction 
3.multiply 
4.divide 
5.exit
enter choice
3
multiply is : 10

 enter your choice
1.addition 
2.subraction 
3.multiply 
4.divide 
5.exit
enter choice
4
divide is : 2.50

 enter your choice
1.addition 
2.subraction 
3.multiply 
4.divide 
5.exit
enter choice
5
ibm@IBM:~/mehta$ 
#-------------------------------------------------------------------------------------------------------
