#!/bin/bash

P=941.9152276295132
T=6.075506051110518
M=2.0
X=258.6
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l100.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l100.dat > case4-set2-bl0.00468-l100-bc.dat

P=1883.8304552590264
T=12.151012102221037
M=2.0
X=136.0
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l200.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l200.dat > case4-set2-bl0.00468-l200-bc.dat

P=2825.7456828885397
T=18.226518153331558
M=2.0
X=95.16
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l300.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l300.dat > case4-set2-bl0.00468-l300-bc.dat

P=3767.660910518053
T=24.302024204442073
M=2.0
X=74.74
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l400.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l400.dat > case4-set2-bl0.00468-l400-bc.dat

P=4709.576138147567
T=30.377530255552596
M=2.0
X=62.5
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l500.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l500.dat > case4-set2-bl0.00468-l500-bc.dat

P=5651.491365777079
T=36.453036306663115
M=2.0
X=54.322
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l600.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l600.dat > case4-set2-bl0.00468-l600-bc.dat

P=6593.406593406593
T=42.52854235777363
M=2.0
X=48.49
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l700.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l700.dat > case4-set2-bl0.00468-l700-bc.dat

P=7535.321821036106
T=48.60404840888415
M=2.0
X=44.112
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l800.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l800.dat > case4-set2-bl0.00468-l800-bc.dat

P=8477.23704866562
T=54.67955445999468
M=2.0
X=40.708
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l900.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l900.dat > case4-set2-bl0.00468-l900-bc.dat

P=9419.152276295134
T=60.75506051110519
M=2.0
X=37.9871
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l1000.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l1000.dat > case4-set2-bl0.00468-l1000-bc.dat

P=10361.067503924645
T=66.83056656221571
M=2.0
X=35.759
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l1100.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l1100.dat > case4-set2-bl0.00468-l1100-bc.dat

P=11302.982731554159
T=72.90607261332623
M=2.0
X=33.902
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l1200.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l1200.dat > case4-set2-bl0.00468-l1200-bc.dat

P=14128.728414442698
T=91.13259076665777
M=2.0
X=29.819
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l1500.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l1500.dat > case4-set2-bl0.00468-l1500-bc.dat

P=16954.47409733124
T=109.35910891998935
M=2.0
X=27.097
./blasius-velocity-profile pInf=$P tInf=$T mInf=$M x=$X out=case4-set2-bl0.00468-l1800.dat
awk -f generate-prescribed-case4-set2-bc.awk case4-set2-bl0.00468-l1800.dat > case4-set2-bl0.00468-l1800-bc.dat
