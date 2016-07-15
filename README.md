### ExampleExtension
With g++ compiler it is throwing following linkage errors:
```
CMakeFiles/example_extension.ext.dir/src/example_extension.cpp.o: In function `osquery::ExternalSQLPlugin::getQueryColumns(std::string const&, std::vector<std::tuple<std::string, osquery::ColumnType, osquery::ColumnOptions>, std::allocator<std::tuple<std::string, osquery::ColumnType, osquery::ColumnOptions> > >&) const':
example_extension.cpp:(.text._ZNK7osquery17ExternalSQLPlugin15getQueryColumnsERKSsRSt6vectorISt5tupleIISsNS_10ColumnTypeENS_13ColumnOptionsEEESaIS7_EE[_ZNK7osquery17ExternalSQLPlugin15getQueryColumnsERKSsRSt6vectorISt5tupleIISsNS_10ColumnTypeENS_13ColumnOptionsEEESaIS7_EE]+0x2b): undefined reference to `osquery::getQueryColumnsExternal(std::string const&, std::vector<std::tuple<std::string, osquery::ColumnType, osquery::ColumnOptions>, std::allocator<std::tuple<std::string, osquery::ColumnType, osquery::ColumnOptions> > >&)'
```

But with clang++, it compiles successfully but on execution it is throwing segmentation fault.
