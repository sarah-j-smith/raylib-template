CXX=em++
PROJECT=RaylibStarter
RAYPATH=./raylib-5.0_webassembly
RAY_INC=${RAYPATH}/include
RAY_LIB=${RAYPATH}/lib
SOURCES=$(ls src/*.cpp)
OUT_DIR=public_html
mkdir -p ${OUT_DIR}
${CXX} -o ${OUT_DIR}/${PROJECT}.html ${SOURCES} -Os -Wall ${RAY_LIB}/libraylib.a -I. -I${RAY_INC} -L. -L${RAY_LIB}/libraylib.a -s USE_GLFW=3 --preload-file resources --shell-file src/shell.html -DPLATFORM_WEB
