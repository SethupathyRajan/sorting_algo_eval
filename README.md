This is a sorting algorithm evaluation program . Note : This is still under dev. This is just a basic prototype of this program




This contains three part .


One , the algorithms .


Two , the program to calculate execution time and 


three , the graph plotting python program


For the evaluation first you need run the C program "sorting_algos_eval.c" , which will calculate the execution time of every sorting algorithm using <time.h> for different array sizes


The algorithms will be avail on "all_algos.h" header file




The arrays wiil be avail on the "TempArr" folder with a python program "generate.py" which can generate different test cases


The Arraysize and Execution time will be stored on a CSV file "all_algos_eval.csv"(Make sure the file is empty *excluding the headers* before running the program , it can cause overlapping of data )


After executing the C file , execute the python program "graph.py" to plot the graph from the data of the CSV file using matplotlib.pyplot




