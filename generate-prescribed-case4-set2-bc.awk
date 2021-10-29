BEGIN {
  x = -0.33;
  nz = 2;
  for(i = 0; i < nz; ++i) {
    zvalues[i] = 0.1*i;
  }
}
{
  y = $2;
  u = $3;
  v = $4;
  p = $5;
  t = $6;
  for(i = 0; i < nz; ++i) {
    print x, y, zvalues[i], u, v, 0.0, p, t, 0.0, 0.0;
  }
}
END {
  while(y < 2.0) {
    y = y+0.01;
    for(i = 0; i < nz; ++i) {
      print x, y, zvalues[i], u, v, 0.0, p, t, 0.0, 0.0;
    }
  }
}
