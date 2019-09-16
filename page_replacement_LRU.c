/*
Write a program to demonstrate page replacement algorithm using Least Recently Used
*/




#include<stdio.h>

int main()
{
      int frames[10], temp[10], pages[10];
      int total_pages, m, n, position, k, l, total_frames;
      int a = 0, b = 0, page_fault = 0;
      printf("\nEnter Total Number of Frames:\t");
      scanf("%d", &total_frames);
      for(m = 0; m < total_frames; m++)
      {
            frames[m] = -1;
      }
      printf("Enter Total Number of Pages:\t");
      scanf("%d", &total_pages);
      printf("Enter Values for Reference String:\n");
      for(m = 0; m < total_pages; m++)
      {
            printf("Value No.[%d]:\t", m + 1);
            scanf("%d", &pages[m]);
      }
      for(n = 0; n < total_pages; n++)
      {
            a = 0, b = 0;
            for(m = 0; m < total_frames; m++)  //for pages in the refernce string which are already present in any fo the frames
            {
                  if(frames[m] == pages[n])
                  {
                        a = 1;
                        b = 1;
                        break;
                  }
            }
            if(a == 0)   //if any frames are still empty then this condition will be used
            {
                  for(m = 0; m < total_frames; m++)
                  {
                        if(frames[m] == -1)
                        {
                              frames[m] = pages[n];
			      page_fault++;
                              b = 1;
                              break;
                        }
                  }
            }
            if(b == 0)
            {
                  for(m = 0; m < total_frames; m++)   //make a temproary array for checking which page was least recently used
                  {
                        temp[m] = 0;
                  }
                  for(k = n - 1, l = 1; l <= total_frames - 1; l++, k--)	//k ranges from n-1 to 0 
					//where n is the current page in the refernece string which needs to be added into the frames
					//hence with the help of k we get all the pages before teh current page
					//l ranges from 0 to 2 here
					//as we want on page in the frames which was least recently used we only check for 2 pages which where recently used ...which indirectly indicates that the 3rd frame whose page was not found has to be replaced
                  {
                        for(m = 0; m < total_frames; m++)//this loop is to see which frame was the pages previous used
                        {
                              if(frames[m] == pages[k])
                              {
                                    temp[m] = 1;
                              }
                        }
                  }
                  for(m = 0; m < total_frames; m++)  //the frame whose page was not used in recent time will indicate as the frame whose temp[m]=0
                  {
                        if(temp[m] == 0)
                        position = m;
                  }
                  frames[position] = pages[n];  //copy the page into the frames and this is a page replacement
                  page_fault++;
            }
            printf("\n");
            for(m = 0; m < total_frames; m++)
            {
                  printf("%d\t", frames[m]);
            }
	    if(a==0||b==0)
		{		

			printf("\t*\t");
		}
      }
      printf("\nTotal Number of Page Faults:\t%d\n", page_fault);
      return 0;
}
