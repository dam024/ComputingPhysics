
file(GLOB SRC_FILES
	"src/*.cpp"	#Source files
)

include_directories(ComputingPhysics
	include/	#Public headers
	private/	#Private headers
)

add_library(ComputingPhysics 
	${SRC_FILES}
)