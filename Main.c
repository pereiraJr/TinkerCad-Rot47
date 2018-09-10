const char DECRYPT[]= "!\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
const char ENCRYPT[]= "PQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~!\"#$%&\'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNO";

const String USER_MASTER = "admin";
const String PASSWORD_MASTER = "4249@CC@";
void setup()
	{
		Serial.begin(9600);
		pinMode(13, OUTPUT);


		char input[] = "cachorro";
		String encryptedPass = encryptfy(input);
		login("admin", encryptedPass);

	}

	bool login(String login, String password){
		if((USER_MASTER==login) && (PASSWORD_MASTER==password)){
			Serial.println("Logged In");
			return true;
		}
		Serial.println("Bad Credentials");
		return false;
	}

	void deCryptfy(char input[]){
	   String result;
	   
	   for(int i =0; i < strlen(input); i++){
			int position = getIndexFromEnCryptByElement(input[i]);
            result += DECRYPT[position];
	   }
	   Serial.println(result);
	}

	String encryptfy(char input[]){
	   String result;
	   
	   for(int i =0; i < strlen(input); i++){
			int position = getIndexFromDeCryptByElement(input[i]);
            result += ENCRYPT[position];
	   }
	   return result;
	}

	int getIndexFromDeCryptByElement(char input){
		char *element;
		element = strchr(DECRYPT, input);
		return (int)(element - DECRYPT);
	}

	int getIndexFromEnCryptByElement(char input){
		char *element;
		element = strchr(ENCRYPT, input);
		return (int)(element - ENCRYPT);
	}

	void loop(){}
