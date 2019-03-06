// worker_blobs.js
var myBlob = null;

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
      files: [],
      // This is where the list of Blob objects go
      // Since Blobs don't have names (unlike Files),
      // we need to explicitly define one
      blobs: [{
        name: "blob.txt",
        data: myBlob
      }]
    }, '/data');

    // Output contents of file blob.txt, which points to the Blob object
    fileContents = FS.readFile("/data/blob.txt", { encoding: "utf8" });
    console.log("File contents:");
    console.log(fileContents);

    // Done
    self.postMessage("Got it");
  }
};

// Process messages sent to this worker
// (we represent the scope using self instead of window)
self.onmessage = msg => {
  myBlob = msg.data;
  // Import a WebAssembly module we used previously for file manipulation
  self.importScripts("file.js");
}
