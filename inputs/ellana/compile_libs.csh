

cd NormAna/
ls
make realclean
make
cd ..
mv libNormAna.so backup/.
ln -s NormAna/libNormAna.so libNormAna.so

cd NormAna_R/
ls
make realclean
make
cd ..
mv libNormAna_R.so backup/.
ln -s NormAna_R/libNormAna_R.so libNormAna_R.so

cd BBNormAna/
ls
make realclean
make
cd ..
mv libBBNormAna.so backup/.
ln -s BBNormAna/libBBNormAna.so libBBNormAna.so

cd handlib/
ls
make realclean
make
cd ..
mv libHAND.so backup/.
ln -s handlib/libHAND.so libHAND.so

cd bigbitelib/
ls
make realclean
make
cd ..
mv libBigBite.so backup/.
ln -s bigbitelib/libBigBite.so libBigBite.so

# Don't forget to do the following by hand:
#
#  analyzer
#    .L ReplayCore.C+
#
#  cd onlineGui
#     analyzer
#        .L online.C+
#     cd ..
#  ln -s onlineGUI/online_C.so online_C.so
#
# analyzer
#   .L rootlogon.C+
#
#


