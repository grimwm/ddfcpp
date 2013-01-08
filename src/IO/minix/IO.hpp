static inline int InstallInterruptHandler(id_t irq, id_t *id)
{
  return sys_irqsetpolicy(irq, 0, id);
}

static inline int EnableInterruptHandler(id_t *id)
{
  return sys_irqenable(id);
}

static inline unsigned long ReadByte(int port)
{
  unsigned long byte = 0;
  sys_inb(port, &byte);
  return byte;
}

static inline unsigned long ReadWord(int port)
{
  unsigned long word = 0;
  sys_inw(port, &word);
  return word;
}

static inline unsigned long ReadDWord(int port)
{
  unsigned long dword = 0;
  sys_inl(port, &dword);
  return dword;
}

static inline void WriteByte(int port, unsigned long byte)
{
  sys_outb(port, byte);
}

static inline void WriteWord(int port, unsigned long word)
{
  sys_outw(port, word);
}

static inline void WriteDWord(int port, unsigned long dword)
{
  sys_outl(port, dword);
}
