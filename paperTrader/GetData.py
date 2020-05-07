import numpy as np
import yfinance as yf
import datetime as dt
from pandas_datareader import data as pdr

yf.pdr_override()

# Pulls data[Ticker symbol, market price] for selected stock and appends to data array
def getStockData(stock, data):
    # Set date range for api pull
    now=dt.datetime.now()
    if (dt.datetime.today().weekday() == 6):                            # If sunday, pull data for last 48 hours
        lastDay = now - dt.timedelta(hours=48)
    else:
        lastDay = now - dt.timedelta(hours=24)

    # Fetch a dataframe from Yahoo finance api of data from start to now
    df = pdr.get_data_yahoo(stock, lastDay, now)
    df.insert(0, "Stock_Name", stock)
    df["Diff"] = df["Close"].sub(df["Open"], axis = 0)
    rows = len(df.index)

    # Parse individual information for last row in data frame
    stockName = df.iloc[rows-1:rows, 0:1].values.flatten(order='C')
    stockClose = df.iloc[rows-1:rows, 4:5].values.flatten(order='C')

    # Round to 2 decimals
    stockClose = np.around(stockClose, decimals=2)

    # Append to data array
    newData = np.stack((stockName, stockClose))
    data = np.append(data, newData, axis=1)

    return data

# Returns an array of stock data for all ticker symbols in SaveData.txt
def getAllStockData():
    # Get ticker list from saved data file, load to tickerList
    file = 'SaveData.txt'
    tickerList = np.loadtxt(file, dtype=str)
    tickerList = tickerList.tolist()

    # Data: [Ticker symbol, market price]
    data = np.array([[],[]])

    # Loop through each element in tickerList, pulling market information and filling data array
    if isinstance(tickerList, list):
       for x in tickerList:
            if (x[0] != "portBal" and x[0]!= "bookVal"
                and x[0]!= "PL" and x[0]!="funds"):
                data = getStockData(x[0], data)
    else:
        data = getStockData(tickerList, data)

    return data.transpose()

myData = getAllStockData()

# Save output to Data.txt
np.savetxt("Data.txt", myData, fmt='%s')
