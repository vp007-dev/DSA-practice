import numpy as np
from astropy.io import fits
from astropy.stats import sigma_clipped_stats
from photutils.detection import DAOStarFinder
import matplotlib.pyplot as plt


plt.switch_backend('TkAgg')  


fits_file = 'carina_hard.fits' 
hdu = fits.open(fits_file)


image_data = hdu[0].data


image_data = np.nan_to_num(image_data, nan=np.nanmedian(image_data), posinf=np.nanmedian(image_data), neginf=np.nanmedian(image_data))

mean, median, std = sigma_clipped_stats(image_data, sigma=3.0)

daofind = DAOStarFinder(fwhm=3.0, threshold=5.*std)
sources = daofind(image_data - median)

filtered_sources = sources[sources['flux'] > 100]


x_positions = filtered_sources['xcentroid']
y_positions = filtered_sources['ycentroid']
flux_values = filtered_sources['flux']


fig, ax = plt.subplots()


ax.imshow(image_data, cmap='inferno', origin='lower', vmin=median-std, vmax=median+5*std)


sc = ax.scatter(x_positions, y_positions, c=flux_values, cmap='hot', s=50, edgecolor='white', alpha=0.75)


cbar = plt.colorbar(sc, ax=ax, label='Intensity (Flux)')


ax.set_title('Heat Map of Detected Stars Based on Intensity (Flux > 100)')
ax.set_xlabel('X Pixel')
ax.set_ylabel('Y Pixel')


plt.show(block=True)
