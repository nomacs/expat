@import "version.inc";
@import "outercurve.inc";

package {
    name: "expat[${flavor}]";
    version: "${package-version}";
    arch : "${arch}";
    
    display-name: "Expat";
    location: "http://coapp.org/repository/${OutputFilename}";

    feed: "http://coapp.org/repository/packages.atom.xml";
    publisher: "CoApp Project";
}

files[exes] {
    root: @"..\win32\bin\${arch}\Release\";
    
    include: {
        "xmlwf.exe",
    };
    
    trim-path: all;
};


files[dlls] {
    root: @"..\win32\bin\${arch}\Release\";
  
    include: {
        "libexpat.dll",
		"libexpatw.dll",
    };
    
    trim-path: all;
};

license[MIT] {
    license-url: "http://www.lua.org/license.html";
    license-type: "MIT";
}

files[files-to-sign] {
    include: { 
        exes,
        dlls
    };    
}

metadata {
    summary: "The Expat XML Parser";
    description:  @"Expat is an XML parser library written in C. It is a stream-oriented parser in which an application registers handlers for things the parser might find in the XML document "; 

    icon: @"expat.png";
    
    author-version : "2.0.1";
    bug-tracker: "https://github.com/coapp-packages/lua/issues";
    stability : "0";
    licenses : {
        MIT
    };
}

compatability-policy {
    minimum: "2.0.1";
    maximum: "${OneLessThanCurrent}"; // this is the default
    versions : {
        "2.0",
    }; // if not specified, find the versions by looking at the feeds and finding all the major/minor versions in range.
}

application {
    include : {
        exes,
    };
}

manifest[things-that-need-them] {
    // all of our EXEs need to get the manifest entries for the assemblies we're creating in this package
    
    assembly : {
        expat
    };
    
    include : { 
        exes
    };
}

assembly[expat] {
    include : {
        dlls
    };
}

package-composition {
    symlinks : { 
        exes => @"${bin}\${each.Name}" = @"${packagedir}\${each.Name}";
    };
}

signing {
    attributes : {
        company="Outercurve Foundation",
        description="The Expat XML Parser",
        product-name="lua",
        product-version="${package-version}",
        file-version="${package-version}",
    };
    
    replace-signature: true; 
    include: { 
        files-to-sign
    };    
}