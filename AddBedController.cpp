#include "AddBedController.h"

AddBedController* AddBedController::anInstance = NULL; // Global static pointer used to ensure a single instance of the class.

AddBedController* AddBedController::getInstance()
{
    if(!anInstance) //If it is doesn't already exist
        anInstance = new AddBedController; //Create a new instance, new for the heap.

    return anInstance;//Return the instance.
}

AddBedController::AddBedController()
{
}

QString AddBedController::addtoBed(QString aNumberBed, QString aType, Hospital *aFacility)
{
    bool ok; //to make sure the conversion String to number Worked;
    int numberBedInt; //To hold the String to int
    numberBed = aNumberBed;
    type = aType;
 //   facility = aFacility;
 //   Hospital * aFacility2 = new Hospital("TheFacility","Ottawa"); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE
 //   LongTermCare * aFacility3 = new LongTermCare("TheFacility","Ottawa"); //Will use the main facility list, but for now.LEt's assume 1 facility TO CHANGE

    numberBedInt = numberBed.toInt(&ok);

    //Verify if it is a integer. If it isn't, return -1;
    if (!ok)
    {
        return "-1";
    }

    if(aType == "Acute")
    {
        if (numberBedInt < 0)
        {
            if(!aFacility->removeBedAcute(numberBedInt))
                return "-1";
        }
        else
        {
            for (int i=0; i< numberBedInt ; i++)
            {
                aFacility->addBedAcute();
            }
        }
        numberBed.setNum(aFacility->getSizeAcute()); //Set as integer

    }
    else
        if(aType == "Complex")
        {
            if (numberBedInt < 0)
            {
                if(!aFacility->removeBedComplex(numberBedInt))
                    return "-1";
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility->addBedComplex();
                }
            }
            numberBed.setNum(aFacility->getSizeComplex()); //Set as integer

        }
/*    else
        if(aType == "LTC")
        {
            if (numberBedInt < 0)
            {
                if(!aFacility3->removeBedLTC(numberBedInt))
                    return "-1";
            }
            else
            {
                for (int i=0; i< numberBedInt ; i++)
                {
                    aFacility3->addBedLTC();
                }
            }
            numberBed.setNum(aFacility3->getSizeLTC()); //Set as integer

        }*/

    return numberBed  ;
}



/*        for (int i=0; i< numberBedInt; i++) //Add numberBedInt # of bed           //TO BE USED IF WE WANT TO CREATE IT FROM HERE AND NOT FROM FACILITY, BUT IT DOESNT WORK. PASSO NLY POINTER
        {
            Bed * aBed = new Bed();
            listBed.append(aBed); //Add at the end of the list
        }
        aFacility2->addBed(&listBed);

        */
