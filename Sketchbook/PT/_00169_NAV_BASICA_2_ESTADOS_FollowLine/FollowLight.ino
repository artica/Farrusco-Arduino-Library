void FollowLight() 
{
     pChoquesEsq = farrusco.PChoqueEsqValor();  
     pChoquesDir = farrusco.PChoqueDirValor();
  
  if (pChoquesEsq == 1) 
  {
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    Beco (2);
  }
  else 
  {
  

    LDREsq = analogRead (LDREsq_pin);
    LDRDir = analogRead (LDRDir_pin);
    
    //Farrusco procura a luz
    velocidadeMotorEsq = map (LDREsq, 0, 1023, 0, 255);
    velocidadeMotorDir = map (LDRDir, 0, 1023, 0, 255);
    
    farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  } 
}
int irPins[]={A1,A2,A3,A4};
int threshold =550;
bool line[4];

void FollowLine() 
{
  int resTemp;

     pChoquesEsq = farrusco.PChoqueEsqValor();  
     pChoquesDir = farrusco.PChoqueDirValor();  
  
  if (pChoquesEsq == 1) 
  {
    Beco (1);
  }
  else if (pChoquesDir == 1) 
  {
    Beco (2);
  }
  else 
  {

  // Farrusco will seek for light if the motorSpeedLeft is assigned the LDR_Right
  //  velocidadeMotorEsq = map (LDREsq, 0, 1023, 0, 255);
  //  velocidadeMotorDir = map (LDRDir, 0, 1023, 0, 255);
   for(int count =0; count < 4; count++)
   {  
     resTemp = analogRead(irPins[count]);
     line[count]= resTemp>threshold;
     Serial.print(" ");
     Serial.print(line[count]);
 
   }
   Serial.println();
   //apenas sensor Ext Esq
   if(line[0] && !line[1])
   {
     velocidadeMotorEsq = 230;
     velocidadeMotorDir = -200;
   }
   //apenas Ext Esq e  Esq
   else if(line[0] && line[1])
   {
     velocidadeMotorEsq = 230;
     velocidadeMotorDir = 200;
   }
   //apenas Esq
   else if(line[1] && !line[2])
   {
     velocidadeMotorEsq = 230;
     velocidadeMotorDir = 230;
   }
   //apenas Esq e Dir
   else if(line[1] && line[2])
   {
     velocidadeMotorEsq = 250;
     velocidadeMotorDir = 250;
   }
   //apenas Dir
   else if(line[2] && ! line[3])
   {
     velocidadeMotorEsq = 230;
     velocidadeMotorDir = 230;
   }
   //apenas Ext Dir e Dir
   else if(line[2] && line[3])
   {
     velocidadeMotorEsq = 200;
     velocidadeMotorDir = 230;
   }
   //apenas Ext Dir
    else if(line[3]&& !line[2])
   {
     velocidadeMotorEsq = -200;
     velocidadeMotorDir = 230;
   }
  farrusco.ActuadorMotores(velocidadeMotorEsq, velocidadeMotorDir);
  } 
}
