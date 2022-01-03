Ques -> Find max 10 numbers in a list having 10M entries.

Solution ->

1. Brute force 

	We will sort the array of entries and return the last 10 numbers from it
	Time - O(NlogN) if we use merge sort
	Space - O(1) as we are not using any extra space
	
2. Optimize way

	Use Min heap
	
	a) We can create a min heap and start pushing entries into in  
	b) When it reaches 10 entries so for the next new entry we will check 
		
        a. if the top of the min heap which will be the min element among 
            those 10 entries is smaller than the next new entry if it is 
            smaller then we will pop out the top element from our heap

		b. Otherwise we will not do anything

	c) We will continue this for all our entries 
	d) At the end we will get our all top 10 max numbers

Time⌚ and Space complexity

	Let 'k' is the amount of max numbers we want from entries then ,
	
	Time -> O(NlogK)
	logk for min heap every time we push a new number it will take log k 
    time to take it's position in the heap
	
	Space -> O(k) 
