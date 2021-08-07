add_library(fancylib STATIC)
luastg_target_common_options(fancylib)
target_include_directories(fancylib PUBLIC
    .
    fcyFile
    fcyIO
    fcyMisc
    fcyNet
    fcyOS
    fcyParser
)
target_sources(fancylib PRIVATE
    fcyType.h
    fcyException.h
    fcyException.cpp
    fcyRefObj.h
    fcyMath.h
    
    fcyFile/fcyModelBoundingBoxLabel.cpp
    fcyFile/fcyModelBoundingBoxLabel.h
    fcyFile/fcyModelIndexLabel.cpp
    fcyFile/fcyModelIndexLabel.h
    fcyFile/fcyModelLabel.cpp
    fcyFile/fcyModelLabel.h
    fcyFile/fcyModelMaterialLabel.cpp
    fcyFile/fcyModelMaterialLabel.h
    fcyFile/fcyModelMeshExporter.cpp
    fcyFile/fcyModelMeshExporter.h
    fcyFile/fcyModelMeshFile.cpp
    fcyFile/fcyModelMeshFile.h
    fcyFile/fcyModelSubsetLabel.cpp
    fcyFile/fcyModelSubsetLabel.h
    fcyFile/fcyModelVertexLabel.cpp
    fcyFile/fcyModelVertexLabel.h
    fcyFile/fcyResPackage.cpp
    fcyFile/fcyResPackage.h
    
    fcyIO/fcyBinaryHelper.cpp
    fcyIO/fcyBinaryHelper.h
    fcyIO/fcyDeflate.cpp
    fcyIO/fcyDeflate.h
    fcyIO/fcyStream.cpp
    fcyIO/fcyStream.h
    
    fcyMisc/fcyFunctor.h
    fcyMisc/fcyHash.cpp
    fcyMisc/fcyHash.h
    fcyMisc/fcyRandom.cpp
    fcyMisc/fcyRandom.h
    fcyMisc/fcyStopWatch.cpp
    fcyMisc/fcyStopWatch.h
    fcyMisc/fcyStringHelper.cpp
    fcyMisc/fcyStringHelper.h
    
    fcyNet/fcyHTTP.cpp
    fcyNet/fcyHTTP.h
    
    fcyOS/fcyCPUID.cpp
    fcyOS/fcyCPUID.h
    fcyOS/fcyDebug.cpp
    fcyOS/fcyDebug.h
    fcyOS/fcyMemPool.h
    fcyOS/fcyMultiThread.cpp
    fcyOS/fcyMultiThread.h
    fcyOS/fcySocket.cpp
    fcyOS/fcySocket.h
    
    fcyParser/fcyIni.cpp
    fcyParser/fcyIni.h
    fcyParser/fcyJson.cpp
    fcyParser/fcyJson.h
    fcyParser/fcyLexicalParser.cpp
    fcyParser/fcyLexicalParser.h
    fcyParser/fcyPathParser.cpp
    fcyParser/fcyPathParser.h
    fcyParser/fcyXml.cpp
    fcyParser/fcyXml.h
)
target_link_libraries(fancylib PUBLIC
    zlib
)
