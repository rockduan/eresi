/**
 * $Id: vectors.c,v 1.4 2007-02-23 05:27:47 may Exp $
 *
 *  Initialize the instruction and opcode vectors.
 */

#include <libasm.h>

/**
 * Default handler for the disasm vector.
 * This handler does nothing, simply returning -1.
 * @param ins Pointer to instruction structure to fill
 * @param opcode Pointer to buffer to disassemble
 * @param len Length of the buffer to disassemble
 * @param proc Pointer to the processor structure
 * @return -1
 */
int	asm_fetch_default(asm_instr *ins, u_char *opcode, u_int len, 
			  asm_processor *proc)
{
  if (proc->type == ASM_PROC_SPARC)
  	return asm_sparc_illegal(ins, opcode, len, proc);
  else	
    return (-1);
}

/**
 * Intialize the disasm vector
 * @param proc Pointer to the processor structure
 * @return 1 on success, 0 on error
 */
int	asm_init_vectors(asm_processor *proc)
{
  u_int	*dims;
  char	**dimstr;
  
  aspect_init();
  
  dims = malloc(4 * sizeof (u_int));
  if (!dims)
    return (0);
  dimstr = malloc(4 * sizeof (char *));
  if (!dimstr)
    return (0);
  
  dims[0] = LIBASM_VECTOR_ARCHNUM;
  dims[1] = 512;
  dims[2] = 64;
  dims[3] = 32;
  
  dimstr[0] = "MACHINE";
  dimstr[1] = "OPCODES";
  dimstr[2] = "SECONDARY OPCODES (SPARC ONLY)"; /* Should be 0 when unused */
  dimstr[3] = "FPOP OPCODE (SPARC ONLY)"; /* Should be 0 when unused */
  aspect_register_vector("disasm",
			 asm_fetch_default,
			 dims, dimstr, 4, ASPECT_TYPE_CADDR);
  return (1);
}