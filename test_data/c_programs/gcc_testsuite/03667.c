







struct A { char e; char f; };

long
foo (void)
{
  return (((4096UL - (long) &((struct A *) 0)->f) & 0xffff0000) ? ((((4096UL - (long) &((struct A *) 0)->f) >> 16) & 0x0000ff00) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) & 0x000000f0) ? ((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 4) & 0x0000000c) ? (((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 4) >> 2) & 0x00000002) ? 0x2 : ((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 4) >> 2) & 0x1)) << 2 : ((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 4) & 0x00000002) ? 0x2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 4) & 0x1))) << 4 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) & 0x0000000c) ? ((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 2) & 0x00000002) ? 0x2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) >> 2) & 0x1)) << 2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 8) & 0x1)))) << 8 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) & 0x000000f0) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 4) & 0x0000000c) ? ((((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 4) >> 2) & 0x00000002) ? 0x2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 4) >> 2) & 0x1)) << 2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 4) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 4) & 0x1))) << 4 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) & 0x0000000c) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 2) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) >> 2) & 0x1)) << 2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 16) & 0x00000002) ? 0x2 : (((4096UL - (long) &((struct A *) 0)->f) >> 16) & 0x1))))) << 16 : (((4096UL - (long) &((struct A *) 0)->f) & 0x0000ff00) ? ((((4096UL - (long) &((struct A *) 0)->f) >> 8) & 0x000000f0) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 4) & 0x0000000c) ? ((((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 4) >> 2) & 0x00000002) ? 0x2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 4) >> 2) & 0x1)) << 2 : (((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 4) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 4) & 0x1))) << 4 : ((((4096UL - (long) &((struct A *) 0)->f) >> 8) & 0x0000000c) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 2) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 8) >> 2) & 0x1)) << 2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 8) & 0x00000002) ? 0x2 : (((4096UL - (long) &((struct A *) 0)->f) >> 8) & 0x1)))) << 8 : (((4096UL - (long) &((struct A *) 0)->f) & 0x000000f0) ? ((((4096UL - (long) &((struct A *) 0)->f) >> 4) & 0x0000000c) ? (((((4096UL - (long) &((struct A *) 0)->f) >> 4) >> 2) & 0x00000002) ? 0x2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 4) >> 2) & 0x1)) << 2 : ((((4096UL - (long) &((struct A *) 0)->f) >> 4) & 0x00000002) ? 0x2 : (((4096UL - (long) &((struct A *) 0)->f) >> 4) & 0x1))) << 4 : (((4096UL - (long) &((struct A *) 0)->f) & 0x0000000c) ? ((((4096UL - (long) &((struct A *) 0)->f) >> 2) & 0x00000002) ? 0x2 : (((4096UL - (long) &((struct A *) 0)->f) >> 2) & 0x1)) << 2 : (((4096UL - (long) &((struct A *) 0)->f) & 0x00000002) ? 0x2 : ((4096UL - (long) &((struct A *) 0)->f) & 0x1))))));
}
