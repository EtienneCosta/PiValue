time ./calculo 2 20000 > estimativa2_20000.txt 

time ./calculo 2 100000 > estimativa2_100000.txt 

time ./calculo 2 1000000 > estimativa2_1000000.txt 

time ./calculo 2 10000000 > estimativa2_10000000.txt 

mkdir Outputs2Threads 
mv *.txt /Users/etiennecosta/Desktop/Pi/Outputs2Threads

time ./calculo 4 20000 > estimativa4_20000.txt 

time ./calculo 4 100000 > estimativa4_100000.txt 

time ./calculo 4 1000000 > estimativa4_1000000.txt 

time ./calculo 4 10000000 > estimativa4_10000000.txt 

mkdir Outputs4Threads 
mv *.txt /Users/etiennecosta/Desktop/Pi/Outputs4Threads

time ./calculo 6 20000 > estimativa6_20000.txt 

time ./calculo 6 100000 > estimativa6_100000.txt 

time ./calculo 6 1000000 > estimativa6_1000000.txt 

time ./calculo 6 10000000 > estimativa6_10000000.txt 

mkdir Outputs6Threads 
mv *.txt /Users/etiennecosta/Desktop/Pi/Outputs6Threads

time ./calculo 8 20000 > estimativa8_20000.txt 

time ./calculo 8 100000 > estimativa8_100000.txt 

time ./calculo 8 1000000 > estimativa8_1000000.txt 

time ./calculo 8 10000000 > estimativa8_10000000.txt 

mkdir Outputs8Threads 
mv *.txt /Users/etiennecosta/Desktop/Pi/Outputs8Threads