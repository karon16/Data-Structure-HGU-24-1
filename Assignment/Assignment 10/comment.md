# Provide a comment on why you select the algorithm
### Answer: I chose to sort the data in this project using the ```Quick Sort algorithm``` .
1. The main reason is that I have two array to sort at the same time (The word list array and the word frequency array). 
```Quick sort``` made it easy for me to sort both arrays within one process basing my index manipulation on the word 
frequency array to sort by Integer value and the apply the same result to the word list array.


2. The time complexity for the ```Quick Sort``` is ```O(nlog(n))``` which is similar to merge sort. 
However, ```Merge Sort``` would have constrained me to sort separately the word list array and the word 
frequency array. The worst case for the ```Quick Sort``` is ```O(n^2)```  only when the array is already 
sorted which we can be sure is not likely to be the case for our current project

3. Also the space complexity of ```Quick Sort``` is ```O(log(n))``` which is quite good.
