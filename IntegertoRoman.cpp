/*
Given an integer, convert it to a roman numeral.

Input is guaranteed to be within the range from 1 to 3999.
*/

 string intToRoman(int num) {   
       const char roman[]="IVXLCDM";
       //I（1）、V（5）、X（10）、L（50）、C（100）、D（500）和M（1000）
       //http://zh.wikipedia.org/wiki/罗马数字
      string result;
      int offset=0;
      while(num>0){
          int curr=num%10;
          num/=10;
          string tmp;
          if(curr==9){
              tmp+=roman[offset];
              tmp+=roman[offset+2];
          }else if(curr==4){
              tmp+=roman[offset];
              tmp+=roman[offset+1];
          }else{
              if(curr>=5){
                  tmp+=roman[offset+1];
                  curr-=5;
              }
              for(int i=0;i<curr;++i){
                  tmp+=roman[offset];    
              }
          }
          result=tmp+result;
          offset+=2;
      }
      return result;
  }
