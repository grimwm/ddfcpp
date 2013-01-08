static inline void Panic(char * const id, char * const reason, int errnum)
{
  panic(id, reason, errnum);
}
