######################################################################
# 				SameEventPairMaker
######################################################################

InitialDir = /home/jdb12/work/muonAna/bin/
Executable = /home/jdb12/work/muonAna/bin/prod
Arguments  = /home/jdb12/work/muonAna/bin/config/Tasks/MuonCandidateQA.xml --jobIndex=$(Process) --R:active=Run15_PP_200_Mtd --mod=_EVENT_PID

GetEnv     = True

Queue 55