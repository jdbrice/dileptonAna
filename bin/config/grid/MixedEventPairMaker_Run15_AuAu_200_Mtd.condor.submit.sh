######################################################################
# 				MixedEventPairMaker
######################################################################

InitialDir = /home/jdb12/work/muonAna/bin/
Executable = /home/jdb12/work/muonAna/bin/prod
Arguments  = /home/jdb12/work/muonAna/bin/config/Tasks/MixedEventPairMaker.xml --jobIndex=$(Process) --R:active=Run15_PP_200_Mtd --MM.input.dst:splitBy=20 --mod=_NOMINAL

GetEnv     = True

Queue 20