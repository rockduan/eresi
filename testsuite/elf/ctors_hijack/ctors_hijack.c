/*
** ctors_hijack.c for testsuite in ERESI
** 
** Started on  Sun Mar 10 01:18:51 2002 jfv
** $Id$
*/
#include	"libelfsh.h"

#if ERESI32
 #define		TROJANED_FILE	"./hijackme32"
 #define		OUTPUT_FILE	"./fake_aout32"
#elif ERESI64
 #define		TROJANED_FILE	"./hijackme64"
 #define		OUTPUT_FILE	"./fake_aout64"
#endif

int		main(int argc, char **argv)
{
  elfshobj_t	*file;
  elfsh_Sym	*new_ctors;
  elfsh_Sym	*my_ctors;
  int		ret;


  file = elfsh_map_obj(TROJANED_FILE);
  printf("before elfsh_get_symbol_by_name,new_ctors\n");
  new_ctors = elfsh_get_symbol_by_name(file, "new_ctors");
  my_ctors = elfsh_get_symbol_by_name(file, "my_ctors");
  if (!file || !new_ctors)
    {
      elfsh_error();
      exit(-1);
    }


  /***********************************************************/
  /**************** TEST FOR CTORS HIJACKING *****************/
  /***********************************************************/

  //ret = elfsh_set_ctors_entry_by_index(file, 1, new_ctors->st_value);
  printf("###before new_ctors->st_value=%lu,my_ctors->st_value=%lu\n",new_ctors->st_value,my_ctors->st_value);
  ret = elfsh_set_ctors_entry_by_name(file, "my_ctors", new_ctors->st_value);
//  printf("####change new_ctors,to %d\n",my_ctors->st_value);
//  ret = elfsh_set_ctors_entry_by_name(file, "new_ctors",4448);

  new_ctors = elfsh_get_symbol_by_name(file, "new_ctors");
  my_ctors = elfsh_get_symbol_by_name(file, "my_ctors");
  
  printf("###after new_ctors->st_value=%lu,my_ctors->st_value=%lu\n",new_ctors->st_value,my_ctors->st_value);
  if (ret < 0)
    {
      elfsh_error();
      exit(-1);
    }


  /***********************************************************/
  /************************ RELINKING ************************/
  /***********************************************************/

  ret = elfsh_save_obj(file, OUTPUT_FILE);
  if (ret < 0)
    elfsh_error();

  printf("Relinking *%s* \n", ret ? "Error" : "OK");
  return (0);
}

