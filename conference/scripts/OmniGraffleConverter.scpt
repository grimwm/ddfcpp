on run argv
	if length of argv is 0 then
		return "Usage: OmniGraffleConverter.scpt <infile outfile ...>"
	end if
	
	set i to 0
	repeat with arg in argv
		if i is equal to 0
			set i to i+1
			set infile to (POSIX file arg) as string
		else
			set outfile to (POSIX file arg) as string
			tell application "OmniGraffle"
				activate
		
				open file infile
				save front window in outfile
				delay 0.30
				close front window
			end tell
			set i to i-1
		end if
	end repeat

	delay 1.0
	tell application "OmniGraffle" to quit application saving ask
end run
