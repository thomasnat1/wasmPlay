var myFiles = null;

var Module = {
  // Don't auto-run main()
  noInitialRun: true,
  // When done initializing
  onRuntimeInitialized: () => 
  {
    // Set up the virtual file system inside the worker
    FS.mkdir('/data');
    FS.mount(WORKERFS, {
      // This is where the list of File objects go
      files: myFiles,
      // No Blobs this time
      blobs: []
    }, '/data');

    // List available files
    console.log(FS.readdir("/data"));

    // Done
    self.postMessage("Got it");
  }
};

// Process messages sent to this worker
// (in a WebWorker, we represent scope using self instead of window)
self.onmessage = msg => {
  myFiles = msg.data;
  myFiles.name = "file.txt";
  console.log(myFiles);

  // Import a WebAssembly module we used previously for file manipulation
  self.importScripts("file.js");
}
