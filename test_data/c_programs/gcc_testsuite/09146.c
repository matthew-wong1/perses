






void ProjectOverlay(const float localTextureAxis[2], char *lump)
{
   const void *d = &localTextureAxis;
   int size = sizeof(float)*8 ;
   __builtin_memcpy( &lump[ 0 ], d, size );
}
