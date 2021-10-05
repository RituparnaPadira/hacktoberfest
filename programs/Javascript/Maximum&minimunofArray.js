//Given an array find the maximun and minumun element

//Aproach: -divide array into two parts and compare both parts to get maximun & minumun

function getMinMax(low, high, arr){
    max = arr[low]
    min = arr[low]
    //base case if only one element present
    if(low === high){
        return (max , min)
    }
    //when 2 elements are present
    if(high == low+1){
        if(arr[low] > arr[high]){
            max = arr[low]
            min = arr[high]
        }else{
            max = arr[high]
            min = arr[low]
        }
        return (max , min)    
    }

    if(high > low +2){
      mid = Math.floor((low + high) / 2)
      max1, min1 = getMinMax(low, mid, arr)
      max2, min2 = getMinMax(mid+1, high, arr)

      return (Math.max(max1, max2), Math.min(min1, min2))
    }

}