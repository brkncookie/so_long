#include "so_long.h"

int validpath(t_cord cord)
{
	t_cord tmp;
	
	tmp = cord;
   	if((cord.rp == cord.re) && (cord.rp == cord.re))
   	{
      cord.sol[cord.rp][cord.cp] = '1';
      return 0;
   	}
   	if(cord.rp >= 0 && cord.cp >= 0 && cord.rp < cord.rlen && cord.cp < cord.clen && \
		   cord.sol[cord.rp][cord.cp] == 0 && cord.map[cord.rp][cord.cp] != '1')
   	{

	 	cord.sol[cord.rp][cord.cp] = '1';
		tmp.rp++;
      	if(validpath(tmp) > -1)
			return(0);
		tmp.rp--;
		tmp.cp++;
      	if(validpath(tmp) > -1)
			return(0);
		tmp.cp--;
		tmp.rp--;
      	if(validpath(tmp) > -1)
			return(0);
		tmp.rp++;
		tmp.cp--;
      	if(validpath(tmp) > -1)
			return(0);
	 	cord.sol[cord.rp][cord.cp] = 0;
      	return (-1);
   	}
   	return (-1);
}
