To write a shell scripting to iconvert a string from upper case to lower case or vice versa


while :
do
	echo "STRING CONVERSION"
	echo "1->lower to upper"
	echo "2->upper to lower"
	echo "3->convert first char"
	echo "4->convert only given char"
	echo "5->exit"
	echo "ENter choice"
	read ch
	case $ch in
	  1)	echo "ENter string in lower case"
	  	read s1
	  	result=`echo $s1 | tr '[a-z]' '[A-Z]'`
	  	echo $result
	  	;;
	  	
	  2)	echo "Enter string in upper case"
	  	read s1
	  	result=`echo $s1 | tr '[A-Z]' '[a-z]'`
	  	echo $result
	  	;;
	  	
	  3)	echo "ENter a string in lower case"
	  	read s1
	  	result=${s1^}
	  	echo $result
	  	;;
	  	
	  4)	echo "Enter the string in lower case"
	  	read s1
		echo "Enter the char"
		read s2
		result=${s1^^[s2]} 
		echo $result 	
	  	;;
	  	
	  5)	exit
	  	;;
	  *)	echo "Enter valid choice"
	esac	
done
