class FileOperation//Creating class for file handling
{

  private:
  string fileName;
    
  public:
  FileOperation(string fName=""):fileName(fName){}//constructor
   
  void setFileName(string fName)//set methods and get methods

    {
      fileName = fName;
    }

  string getFileName()
  
    {
      return fileName;
    }
    
    virtual void fileReadOperation()=0;//pure virtual function
    
    
    
};
