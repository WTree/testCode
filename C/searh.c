#include<stdio.h>
/**
* 冒泡实现排序
*/
void sort(int arr[],int size){
	int i=0,j=0,temp=0;
	for(i=0;i<size;i++){
		
		for(j=0;j<size-1-i;j++){
			
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
	
			}
			
		}
	}

}

/**
二分法查找
*/
int search(int arr[],int start,int end,int element){
	int mid=(start+end)/2;
	if(end<start){
	   return -1;
	}
	if(arr[mid]>element){
		
		return search(arr,mid+1,end,element);	
	
	}else if(arr[mid]<element){
		
		return search(arr,start,mid-1,element);
	}else{
		return mid;
	}
	
}

void main(){
	int arr[]={55,333,0,222,-1,5555,1000};
	int res=0;
	int i=0;
	int length=sizeof(arr)/sizeof(arr[0]); //计算数组长度
	sort(arr,length);
	res=search(arr,0,length-1,222);
	printf("pos = %d",res);
}