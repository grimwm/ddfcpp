static inline int Copy(id_t dst, long dstAddr, id_t src, long srcAddr,
    size_t bytes)
{
  return (sys_datacopy(src, srcAddr, dst, dstAddr, bytes));
}
